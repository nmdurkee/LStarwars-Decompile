/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74eab0; label: FUN_0074eab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0074eab0(char *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char local_204 [512];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_204;
  uVar2 = *param_2;
  FUN_004f6900(local_204);
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar7 = &stack0xfffffdfb;
  do {
    pcVar6 = pcVar7 + 1;
    pcVar7 = pcVar7 + 1;
  } while (*pcVar6 != '\0');
  pcVar6 = param_1;
  for (uVar5 = (uint)((int)pcVar3 - (int)param_1) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = (int)pcVar3 - (int)param_1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  iVar4 = FUN_004f1ff0(local_204);
  if (2 < iVar4) {
    local_204[iVar4 + -3] = 'b';
    local_204[iVar4 + -2] = 'i';
    local_204[iVar4 + -1] = 'k';
  }
  _memset(&DAT_029a99c0,0,0x60);
  iVar4 = FUN_00631940(&DAT_029a99d4,local_204,1,0,0);
  if (iVar4 == 1) {
    _DAT_029a99cc = 0;
    DAT_0297dba8 = 1;
    _DAT_029a99c4 = 0;
    _DAT_029a9a1c = 1;
    _DAT_029a99d0 = 0x3f800000;
    _DAT_029a99c8 = 0x3f800000;
    DAT_029a99c0 = FUN_005e4d00(1);
    if (DAT_029a99c0 != 0) {
      *(undefined2 *)(DAT_029a99c0 + 0x74) = (undefined2)DAT_029a99e8;
      *(uint *)(DAT_029a99c0 + 0x40) = *(uint *)(DAT_029a99c0 + 0x40) & 0xffff3fff;
      *(uint *)(DAT_029a99c0 + 0x40) = *(uint *)(DAT_029a99c0 + 0x40) & 0xfffffff0;
      *(uint *)(DAT_029a99c0 + 0x40) = *(uint *)(DAT_029a99c0 + 0x40) & 0xfffeffff | 0x20000;
      *(uint *)(DAT_029a99c0 + 0x40) = *(uint *)(DAT_029a99c0 + 0x40) & 0xffffffcf;
      FUN_005e4b00(DAT_029a99c0);
      if (DAT_029a99c0 != 0) goto LAB_0074ec6a;
    }
    FUN_0074ea20(&DAT_029a99c0);
    *param_2 = uVar2;
  }
  else {
    _DAT_029a9a1c = 0;
    FUN_00631d00(&DAT_029a99d4);
    if (DAT_029a99c0 != 0) {
      FUN_005e50e0(DAT_029a99c0);
    }
    if (DAT_029a99e8 != 0) {
      FUN_005e5630(DAT_029a99e8);
    }
    _memset(&DAT_029a99c0,0,0x60);
  }
LAB_0074ec6a:
  __security_check_cookie(local_4 ^ (uint)local_204);
  return;
}

