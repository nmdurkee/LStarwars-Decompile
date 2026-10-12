/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x659990; label: FUN_00659990
 */

void FUN_00659990(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  iVar2 = (&DAT_0292fe1c)[DAT_02962010 * 0xb5];
  if ((iVar2 != 8) && (DAT_02924ac8 != -1)) {
    FUN_00659910(iVar2,param_1);
    iVar5 = DAT_0296209c;
    iVar4 = DAT_02962010;
    iVar3 = DAT_02924ac8;
    iVar7 = DAT_02962010 * 0x2d4;
    iVar6 = DAT_02962010 * 0xb5 + iVar2;
    (&DAT_0292feb4)[iVar6] = DAT_02924ac8;
    pcVar9 = *(char **)(iVar5 + iVar3 * 4);
    pcVar8 = &DAT_0292fe34 + iVar7 + iVar2 * 0x10;
    do {
      cVar1 = *pcVar9;
      *pcVar8 = cVar1;
      pcVar9 = pcVar9 + 1;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    (&DAT_0292fed4)[iVar6] = 0x3c;
    (&DAT_0292fef4)[iVar6] = 0;
    (&DAT_0292fe1c)[iVar4 * 0xb5] = (&DAT_0292fe1c)[iVar4 * 0xb5] + 1;
  }
  return;
}

