/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e6f70; label: FUN_004e6f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e6f70(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = (int)param_1;
  FUN_004e6590();
  DAT_0088a4d0 = 0;
  DAT_0088a4d4 = 0;
  _DAT_0088a4d8 = 0;
  _DAT_0088a4dc = 0;
  _DAT_0088a4e0 = 0;
  _DAT_0088a4e4 = 0;
  _DAT_0088a4e8 = 0;
  _DAT_0088a4ec = 0;
  iVar3 = 0;
  if (0 < *(int *)((int)param_1 + 0x50c0)) {
    iVar4 = 0;
    param_1 = &DAT_0088a4d0;
    do {
      if (0x88a4ef < (int)param_1) break;
      iVar5 = *(int *)(iVar1 + 0x50c8) + iVar4;
      iVar2 = FUN_004f8a70(iVar5 + 0xf2,"classic");
      if (iVar2 != 0) {
        *param_1 = iVar5;
        param_1 = param_1 + 1;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x114;
    } while (iVar3 < *(int *)(iVar1 + 0x50c0));
  }
  DAT_0087aa20 = 0;
  DAT_0087a95c = FUN_0051acd0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"In_Cave");
  DAT_0087a9cc = 0;
  DAT_0087a9d0 = 0;
  _DAT_0088a538 = 0;
  _DAT_0088a534 = 0;
  DAT_0088a531 = 0;
  _DAT_0088a540 = 0;
  _DAT_0088a53c = 0;
  _DAT_00800218 = 0x3f000000;
  _DAT_00800214 = 0x3f000000;
  _DAT_00800220 = 0x3f000000;
  _DAT_0080021c = 0x3f000000;
  return;
}

