#define switch(rc, parm, argc, argv, u, cch, ech)
switch((rc) = getuintrc(&parm, argc--, argv++, 0, max, u)) \
  { \
  case ARG_NOERR: \
	break; \
  case ARG_PARAM: \
	cmderror(ERR_NEXTP, NULL, u); \
	return rc; \
  case ARG_QUERY: \
  case ARG_QUESR: \
	engchi(u, ech, cch); \
  default: \
	return rc; \
  }
