/* Ghidra pseudocode; not original source. ev_025be1647cd9629522b41719812f53461a8901c6760c340faf8db7c9df47d95b */

undefined4
FUN_0044d210(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_c;
  float local_8;
  float local_4;
  
  local_4 = 1.0;
  local_8 = 0.0;
  local_c = 1.0;
  if (param_6 != 0) {
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757cd8);
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"time=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"speed=");
            if (iVar1 != 0) {
              fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 6);
              local_c = (float)fVar3;
            }
          }
          else {
            fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 5);
            local_8 = (float)fVar3;
          }
        }
        else {
          fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 4);
          local_4 = (float)fVar3;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
    FUN_00549bb0(PTR_DAT_008021b4,local_4,local_8,local_c);
  }
  return 1;
}

