/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a9450; label: FUN_004a9450
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9450(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 extraout_ST0;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((((param_1 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) != 0)) &&
      ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 1) != 0)) &&
     ((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0 &&
       ((DAT_007f4140 != '\0' || (0.0 < *(float *)(param_1 + 0xdec))))) &&
      ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) != 0)))) {
    fVar3 = *(float *)(param_1 + 0x1dc) * 10.0;
    iVar5 = 0;
    if (0 < DAT_0093d500) {
      iVar6 = 0;
      do {
        iVar1 = DAT_0093d504 + iVar6;
        if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0x1fc) & 1) != 0)) &&
           (((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0 &&
            (((((*(byte *)(*(int *)(iVar1 + 0x54) + 4) & 4) != 0 &&
               ((*(byte *)(iVar1 + 0xef8) & 4) == 0)) &&
              ((*(uint *)(iVar1 + 0xeec) & 0x8000000) == 0)) &&
             ((*(char *)(iVar1 + 0x280) == -1 && (*(char *)(iVar1 + 0x281) == '\0')))))))) {
          fVar7 = (float10)FUN_005b3c50(iVar1 + 0x80,param_1 + 0x80,&local_c);
          fVar2 = *(float *)(iVar1 + 0x1dc) + *(float *)(param_1 + 0x1dc);
          if (fVar2 * fVar2 < (float)fVar7) {
            if ((float)fVar7 < fVar3 * fVar3) {
              FUN_0054ffc0(&local_c,&local_10,&local_14);
              FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0xa00)
                           ,param_1 + 0x5c,0x5a,_DAT_00925018,local_10,local_14,0);
              iVar4 = FUN_006e6b90();
              fVar2 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff];
              FUN_005b37b0(&local_c,&local_c);
              FUN_005b37d0(&local_c,&local_c,param_1 + 0x68);
              FUN_0054fb80(iVar1 + 0x68,iVar1 + 0x68,&local_c,
                           (float)((extraout_ST0 + (float10)fVar2) * (float10)25.0));
              local_c = 0x4e6e6b28;
              local_8 = 0x4e6e6b28;
              local_4 = 0x4e6e6b28;
              FUN_004a8e30(iVar1,&local_c,fVar3);
            }
          }
          else {
            FUN_00438230(0,iVar1,0xffffffff,0,0,1);
            FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
            FUN_0054a8a0(**(undefined4 **)(param_1 + 0xca4),0x3dcccccd,0);
          }
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x10d8;
      } while (iVar5 < DAT_0093d500);
    }
    FUN_00681f40("env_tractorbeam_lp",param_1 + 0x80);
  }
  return;
}

