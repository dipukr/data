	public List<Generation> findEntitledGenerators(Integer utgId, Date forDate) throws BusinessException {
		UtilitiesTraderGenco utg = utgDAO.findOne(utgId);
		List<Integer> utgIds = new ArrayList<>();

		if (utg.getTypeOfUtilities().getType().equals(UtilityType.DISCOMs.name())) {
			Discom discom = discomDAO.getDiscomByUtgId(utgId);
			utgIds.add(discom.getState().getUtilitiesTraderGenco().getUID());
		} else if (utg.getTypeOfUtilities().getType().equals(UtilityType.PPC.name())) {
			PPC ppc = ppcdao.getPPCByUtgId(utg);
			utgIds.add(ppc.getState().getUtilitiesTraderGenco().getUID());
		} else if (utg.getTypeOfUtilities().getType().equals(UtilityType.State.name())) {
		} else if (utg.getTypeOfUtilities().getType().equals(UtilityType.Constituents.name())) {
		} else {
			throw new BusinessException(
					"Specified Utility is of type " + utg.getUtilityType().name() + ", not supported for Entitlement");
		}
		utgIds.add(utgId);

		Set<Generation> set = new HashSet<>();
		for (Integer utilityId : utgIds) {
			List<Generation> allocatedGenerators = findEntitledGenerators(utilityId, forDate, ShareType.ALLOCATED);
			List<Generation> unAllocatedGenerators = findEntitledGenerators(utilityId, forDate, ShareType.UN_ALLOCTED);
			if (unAllocatedGenerators != null && !unAllocatedGenerators.isEmpty()) {
				set.addAll(unAllocatedGenerators);
			}
			if (allocatedGenerators != null && !allocatedGenerators.isEmpty()) {
				set.addAll(allocatedGenerators);
			}
		}

		List<Generation> list = new ArrayList<>();
		if (!set.isEmpty()) {
			list.addAll(set);
			Collections.sort(list);
		}
		return list;
	}

	@Override
	public List<Generation> findEntitledGenerators(Integer utgId, Date forDate, ShareType shareType)
			throws BusinessException {
		List<UtilitiesTraderGenco> findEntitledUtgs = findEntitledUtgs(utgId, forDate, shareType);
		List<Generation> allocatedGencos = null;
		if (findEntitledUtgs != null) {
			allocatedGencos = new ArrayList<>();
			for (UtilitiesTraderGenco utg : findEntitledUtgs) {
				if (utg.getTypeOfUtilities().getType().equals(UtilityType.Generators.name())) {
					Generation gencoByUTG = generationDAO.getGencoByUTG(utg);
					if (gencoByUTG != null)
						allocatedGencos.add(gencoByUTG);
				}
			}
		}
		return allocatedGencos;
	}
	public List<UtilitiesTraderGenco> findEntitledUtgs(Integer utgId, Date forDate, ShareType shareType)
			throws BusinessException {
		List<UtilityShare> shares = findBeneficiarySharesForDate(utgId, forDate, shareType);
		if (shares == null) {
			throw new BusinessException("No share found.");
		}
		List<UtilitiesTraderGenco> allocatedUtgs = new ArrayList<>();
		for (UtilityShare sh : shares) {
			allocatedUtgs.add(sh.getInjectorUtg());
		}
		return allocatedUtgs;
	}
	public List<UtilityShare> findBeneficiarySharesForDate(Integer utgId, Date forDate, ShareType shareType)
			throws BusinessException {
		List<UtilityShare> beneficiarySharesForDate = null;
		try {
			beneficiarySharesForDate = utilityShareDAO.findBeneficiarySharesForDate(utgId, forDate, shareType);
		} catch (ParseException e) {
			throw new BusinessException("Date is not in proper format");
		}
		return beneficiarySharesForDate;
	}

	public List<UtilityShare> findBeneficiarySharesForDate(Integer utgId, Date forDate, ShareType type)
			throws ParseException {
		Assert.notNull(utgId, "Beneficiary Id should not be null");
		Assert.notNull(forDate, "Date should not be null");
		Assert.notNull(type, "Share Type should not be null");
		Date fDate = sdf.parse(sdf.format(forDate));
		return getCurrentSession().createCriteria(clazz).add(Restrictions.eq("beneficiaryUtg.UID", utgId))
				.add(Restrictions.le("fromDate", fDate)).add(Restrictions.ge("toDate", fDate))
				.add(Restrictions.eq("shareType", type)).list();
	}
