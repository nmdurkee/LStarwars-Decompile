/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cdc60; label: FUN_006cdc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cdc60(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 local_124;
  int *piStack_120;
  undefined1 auStack_11c [260];
  uint uStack_18;
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)&local_124;
  local_124 = param_1;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x14))(0);
  uVar1 = DAT_02973ac4;
  do {
    DAT_02973ac4 = uVar1;
    if (iVar2 == 0) {
      __security_check_cookie(uStack_18 ^ (uint)&stack0xfffffed8);
      return;
    }
    iVar3 = FUN_006c6a10(&local_124,iVar2,2,1);
    if ((iVar3 != 0) && ((*(byte *)(piStack_120 + 7) & 2) != 0)) {
      (**(code **)(*piStack_120 + 4))(local_124,uVar1,auStack_11c,0x100);
      iVar3 = FUN_004f8b10(unaff_EBX,auStack_11c);
      if (iVar3 == 0) {
        __security_check_cookie(uStack_18 ^ (uint)&stack0xfffffed8);
        return;
      }
    }
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x14))(iVar2);
    uVar1 = DAT_02973ac4;
  } while( true );
}

