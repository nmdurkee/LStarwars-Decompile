/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x52d9c0; label: FUN_0052d9c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0052d9c0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  int local_14;
  float local_10;
  uint local_c;
  uint local_8;
  undefined1 local_4;
  
  iVar2 = 0;
  local_10 = 0.0;
  local_8 = local_8 & 0xffffff00;
  local_c = local_c & 0xffffff00;
  local_14 = 0;
  if (((param_6 != 0) && (param_2 != 0)) && (0 < param_5)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"priority");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757cf4);
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"state");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757ca8);
            if (iVar1 != 0) {
              fVar3 = (float10)FUN_00514920(param_3,param_2,iVar1 + 5);
              local_10 = (float)fVar3;
            }
          }
          else {
            local_14 = iVar1 + 6;
          }
        }
        else {
          fVar3 = (float10)FUN_00514920(param_3,param_2,iVar1 + 3);
          local_4 = (undefined1)(int)ROUND(fVar3);
          local_c = CONCAT31(local_c._1_3_,local_4);
        }
      }
      else {
        fVar3 = (float10)FUN_00514920(param_3,param_2,iVar1 + 9);
        local_4 = (undefined1)(int)ROUND(fVar3);
        local_8 = CONCAT31(local_8._1_3_,local_4);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_5);
    if (local_14 != 0) {
      FUN_005170c0(param_2,local_8,local_c,local_14,local_10);
    }
  }
  return 1;
}

