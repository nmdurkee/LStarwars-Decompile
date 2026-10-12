/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c8b60; label: FUN_006c8b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c8b60(int param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  int *local_14;
  
  local_1c = 0;
  if (param_1 == 0) {
    if ((*(uint *)(in_ECX + 0x6c) & 1 << (param_3 & 0x1f)) == 0) {
      return 0;
    }
  }
  else {
    iVar1 = FUN_006c6a10(&local_18,param_1,0x100,1);
    if ((iVar1 != 0) && ((local_14[7] & 0x100U) != 0)) {
      (**(code **)(*local_14 + 4))(local_18,DAT_02973aac,local_20,0);
      FUN_004ef660(&local_1c,local_20,2);
    }
    uVar2 = (uint)(short)local_1c;
    if ((uVar2 != 0xffffffff) &&
       ((9 < uVar2 ||
        ((((&DAT_02973f40)[uVar2 * 0x2a] & 2) == 0 && (((&DAT_02973f40)[uVar2 * 0x2a] & 1) != 0)))))
       ) {
      return 0;
    }
  }
  return 1;
}

