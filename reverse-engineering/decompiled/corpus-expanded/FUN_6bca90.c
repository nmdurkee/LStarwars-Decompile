/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bca90; label: FUN_006bca90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bca90(int param_1,int param_2,uint param_3,uint param_4,int param_5,undefined4 param_6,
                 undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar5 = 0;
  FUN_005d0880(2);
  FUN_005d0a40(1);
  FUN_005d0fb0(DAT_009738b8);
  FUN_005d0e80(DAT_009738b8);
  iVar1 = FUN_006e6b90();
  FUN_005d0e80(DAT_009738b8);
  FUN_005d0eb0(DAT_009738b8);
  iVar2 = FUN_006e6b90();
  iVar6 = 0;
  if (0 < param_2) {
    do {
      iVar3 = *(int *)(param_1 + iVar6 * 4);
      if (iVar3 != 0) {
        FUN_005d0d60(DAT_009738b8,iVar3);
        iVar3 = FUN_006e6b90();
        if (iVar5 < iVar3 >> 4) {
          iVar5 = iVar3 >> 4;
        }
        iVar4 = iVar4 + iVar1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_2);
  }
  FUN_005d0a70();
  FUN_005d08c0();
  if (0 < iVar4) {
    if (0x7fffffff < param_3) {
      param_3 = (param_5 - iVar5) - 5;
    }
    if (0x7fffffff < param_4) {
      param_4 = 5;
    }
    FUN_005db880(param_3 << 4,param_4 * 8,iVar5 << 4,iVar4 * 8,param_8,DAT_02973a6c);
    FUN_005d0880(2);
    FUN_005d0a40(1);
    FUN_005d0fb0(DAT_009738b8);
    FUN_005d1060(DAT_009738b8,param_7);
    iVar5 = 0;
    if (0 < param_2) {
      iVar2 = iVar2 + param_4 * 8;
      do {
        iVar4 = *(int *)(param_1 + iVar5 * 4);
        if (iVar4 != 0) {
          FUN_005f35e0(DAT_009738b8,param_3 << 4,iVar2,0x10,iVar4);
          iVar2 = iVar2 + iVar1 * 8;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_2);
    }
    FUN_005d0a70();
    FUN_005d08c0();
  }
  return;
}

