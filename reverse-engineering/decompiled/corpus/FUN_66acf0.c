/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x66acf0; label: FUN_0066acf0
 */

void FUN_0066acf0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_02948eac = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_0066acd0,"GenSort Type");
    if (DAT_02948eac != 0) {
      uVar2 = FUN_00627b80(0,&local_10,*(char *)(iVar1 + 0x2c) == '\0',1,&LAB_006638d0,"Normal");
      FUN_00618e10(DAT_02948eac,uVar2);
      if (*(char *)(iVar1 + 0x2e) == '\a') {
        uVar2 = FUN_00627a80(6,&DAT_008109e8,0,0,0);
        FUN_00618e10(DAT_02948eac,uVar2);
        uVar2 = FUN_00627a80(7,&DAT_008109e8,0,0,0,"Radial Rotor");
      }
      else {
        uVar2 = FUN_00627b80(6,&local_10,*(char *)(iVar1 + 0x2c) == '\x06',1,&LAB_006638d0,"Radial")
        ;
        FUN_00618e10(DAT_02948eac,uVar2);
        uVar2 = FUN_00627b80(7,&local_10,*(char *)(iVar1 + 0x2c) == '\a',1,&LAB_006638d0,
                             "Radial Rotor");
      }
      FUN_00618e10(DAT_02948eac,uVar2);
      uVar2 = FUN_00627b80(8,&local_10,*(char *)(iVar1 + 0x2c) == '\b',1,&LAB_006638d0,"Spheroid");
      FUN_00618e10(DAT_02948eac,uVar2);
      if (*(char *)(iVar1 + 0x2e) == '\a') {
        uVar2 = FUN_00627a80(9,&DAT_008109e8,0,0,0);
        FUN_00618e10(DAT_02948eac,uVar2);
        uVar2 = FUN_00627a80(10,&DAT_008109e8,0,0,0,"BounceXZ");
        FUN_00618e10(DAT_02948eac,uVar2);
        uVar2 = FUN_00627a80(0xb,&DAT_008109e8,0,0,0,"Improved Radial");
        FUN_00618e10(DAT_02948eac,uVar2);
        uVar2 = FUN_00627a80(0xc,&DAT_008109e8,0,0,0,"Star Radial");
      }
      else {
        uVar2 = FUN_00627b80(9,&local_10,*(char *)(iVar1 + 0x2c) == '\t',1,&LAB_006638d0,"BounceY");
        FUN_00618e10(DAT_02948eac,uVar2);
        uVar2 = FUN_00627b80(10,&local_10,*(char *)(iVar1 + 0x2c) == '\n',1,&LAB_006638d0,"BounceXZ"
                            );
        FUN_00618e10(DAT_02948eac,uVar2);
        uVar2 = FUN_00627b80(0xb,&local_10,*(char *)(iVar1 + 0x2c) == '\v',1,&LAB_006638d0,
                             "Improved Radial");
        FUN_00618e10(DAT_02948eac,uVar2);
        uVar2 = FUN_00627b80(0xc,&local_10,*(char *)(iVar1 + 0x2c) == '\f',1,&LAB_006638d0,
                             "Star Radial");
      }
      FUN_00618e10(DAT_02948eac,uVar2);
    }
    FUN_006279b0(param_1,DAT_02948eac);
    *(int *)(DAT_02948eac + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02948eac + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

