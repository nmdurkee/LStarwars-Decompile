/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x645260; label: FUN_00645260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00645260(int param_1)

{
  char *pcVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  local_4 = 0;
  if (DAT_02920a94 < 0x80) {
    iVar5 = 0;
    pcVar1 = &DAT_02913a58;
    do {
      if (*pcVar1 == '\0') {
        iVar4 = iVar5 * 0x178;
        _sprintf(&DAT_02913a58 + iVar4,"New%d",iVar5);
        FUN_006444e0(iVar5);
        DAT_02920a94 = DAT_02920a94 + 1;
        DAT_029208d0 = DAT_02962918;
        iVar2 = 0;
        (&DAT_02913b0b)[iVar4] = 0;
        (&DAT_02913b0a)[iVar4] = 0;
        _DAT_02913a2c = 1;
        _DAT_0292089c = 1;
        DAT_0291f688 = 0;
        puVar3 = &DAT_02913ae8 + iVar5 * 0xbc;
        DAT_00810194 = iVar5;
        do {
          *puVar3 = 0xffff;
          (&DAT_02913af8)[iVar2 + iVar4] = 0xff;
          iVar2 = iVar2 + 1;
          puVar3 = puVar3 + 1;
        } while (iVar2 < 8);
        (&DAT_02913bb8)[iVar5 * 0x5e] = 0x3f800000;
        (&DAT_02913bbc)[iVar5 * 0x5e] = 0x3f800000;
        (&DAT_02913bc0)[iVar5 * 0x5e] = 0x3f800000;
        break;
      }
      pcVar1 = pcVar1 + 0x178;
      iVar5 = iVar5 + 1;
    } while ((int)pcVar1 < 0x291f658);
  }
  iVar5 = *(int *)(param_1 + 0x40);
  if (iVar5 != 0) {
    FUN_006279f0(param_1);
    local_4 = iVar5;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,local_4);
  }
  return;
}

