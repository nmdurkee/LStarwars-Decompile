/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3500; label: FUN_005c3500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005c3500(uint param_1)

{
  char cVar1;
  
  if ((DAT_00971598 & param_1) != 0) {
    switch(param_1) {
    case 4:
      return *(char *)(DAT_009737e0 + 0x89) != '\0';
    case 8:
      return *(char *)(DAT_009737e0 + 0x88) != '\0';
    case 0x10:
      cVar1 = (**(code **)(*DAT_009737e8 + 0x20))();
      return cVar1 != '\0';
    case 0x20:
      cVar1 = (**(code **)(*DAT_009737e4 + 0x20))();
      return cVar1 != '\0';
    case 0x40:
      cVar1 = (**(code **)(*DAT_009737ec + 0x20))();
      return cVar1 != '\0';
    case 0x80:
      cVar1 = (**(code **)(*DAT_009737f0 + 0x20))();
      return cVar1 != '\0';
    }
  }
  return false;
}

