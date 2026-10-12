/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x655e90; label: FUN_00655e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00655e90(uint param_1)

{
  char cVar1;
  short sVar2;
  
  if (((-1 < (int)param_1) && ((int)param_1 < DAT_02962098)) &&
     (*(int *)(DAT_0296209c + param_1 * 4) != 0)) {
    cVar1 = *(char *)(*(int *)(DAT_0296209c + param_1 * 4) + 0x2e);
    param_1 = (uint)cVar1;
    if (param_1 < 8) {
      sVar2 = (short)(cVar1 >> 7);
      switch(param_1) {
      case 0:
        return CONCAT22(sVar2,20000);
      case 2:
        return CONCAT22(sVar2,40000);
      case 3:
        return CONCAT22(sVar2,30000);
      case 7:
        return CONCAT22(sVar2,10000);
      }
    }
  }
  return param_1 & 0xffff0000;
}

