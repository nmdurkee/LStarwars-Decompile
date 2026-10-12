/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cd5c0; label: FUN_006cd5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006cd5c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_EDI;
  undefined1 auStack_28 [4];
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int *local_14;
  
  uVar1 = DAT_02973ab0;
  local_20 = 0;
  local_24 = 0;
  local_1c = 1;
  iVar2 = FUN_006c6a10(&local_18,unaff_EDI,1,1);
  if ((iVar2 != 0) && ((*(byte *)(local_14 + 7) & 1) != 0)) {
    (**(code **)(*local_14 + 4))(local_18,uVar1,&local_24,0);
  }
  iVar2 = FUN_006c6a10(&local_18,unaff_EDI,0x100,1);
  if ((iVar2 != 0) && ((local_14[7] & 0x100U) != 0)) {
    (**(code **)(*local_14 + 4))(local_18,DAT_02973aac,auStack_28,0);
    FUN_004ef660(&local_20,auStack_28,2);
  }
  if (*(int *)(param_1 + 0x10) != (int)(short)local_20) {
    local_1c = 0;
  }
  if ((*(uint *)(param_1 + 0x1c) & 0x400000) == 0) {
    local_24 = local_24 & 0x10000000;
  }
  else {
    local_24 = local_24 & 0x400000;
  }
  if (local_24 != 0) {
    local_1c = 0;
  }
  return local_1c;
}

