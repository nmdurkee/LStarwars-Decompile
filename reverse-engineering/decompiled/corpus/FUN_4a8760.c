/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a8760; label: FUN_004a8760
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a8760(void)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  float10 extraout_ST0;
  
  iVar2 = FUN_0056e160(0x14);
  if ((((iVar2 != 0) && ((*(byte *)(in_EAX + 0x1fc) & 0x80) != 0)) &&
      ((*(uint *)(*(int *)(in_EAX + 0x54) + 4) & 0x2000) != 0)) &&
     (iVar2 = FUN_00594250((int)*(short *)(in_EAX + 0x1064),0,0), iVar2 != -1)) {
    if (*(float *)(in_EAX + 0xd4c) == 0.0) {
      if ((*(uint *)(*(int *)(in_EAX + 0xca4) + 8) & DAT_00802280) != 0) {
        *(float *)(in_EAX + 0xd4c) = _DAT_00925018 + *(float *)(in_EAX + 0xd4c);
        return;
      }
    }
    else if ((*(uint *)(*(int *)(in_EAX + 0xca4) + 4) & DAT_00802280) != 0) {
      iVar2 = FUN_006e6b90();
      fVar1 = _DAT_00925018 + *(float *)(in_EAX + 0xd4c);
      *(float *)(in_EAX + 0xd4c) = fVar1;
      if (NAN(fVar1) || 2.0 < fVar1 == (fVar1 == 2.0)) {
        FUN_00651470("JForceUse",0,fVar1 * 3.0 * 0.5);
        iVar3 = FUN_006e6b90();
        if (iVar3 != iVar2) {
          FUN_0054a8d0(**(undefined4 **)(in_EAX + 0xca4),2,0);
          return;
        }
      }
      else {
        *(float *)(in_EAX + 0xd4c) = (float)extraout_ST0;
        FUN_0056e5f0(in_EAX + 0x80,DAT_00950f60 * 7.5,0x3f800000,0,0xffffffff,0x4021);
        FUN_0054a910(0x3f800000,0x3dcccccd,0,0);
        iVar2 = FUN_0054fa60();
        if (iVar2 < 0x8000) {
          fVar1 = -1.0;
        }
        else {
          fVar1 = 1.0;
        }
        FUN_00549de0(PTR_DAT_008021b4,fVar1 * 1.5,2,0);
        FUN_00549bb0(PTR_DAT_008021b4,0x40000000,0x3f800000,0x3f800000);
        FUN_00681f40("Explode1",0);
      }
      return;
    }
    return;
  }
  *(undefined4 *)(in_EAX + 0xd4c) = 0;
  return;
}

