/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c6400; label: FUN_004c6400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c6400(void)

{
  undefined4 uVar1;
  int iVar2;
  float10 extraout_ST0;
  
  if (0.0 < _DAT_0087bd78) {
    if (DAT_008801ac == 0) {
      iVar2 = (int)DAT_008808e4;
    }
    else if (DAT_008801ac == 1) {
      iVar2 = (int)DAT_008806ec;
    }
    else if (DAT_008801ac == 2) {
      iVar2 = (int)DAT_008808ec;
    }
    else if (DAT_008801ac == 4) {
      iVar2 = (int)DAT_0088075c;
    }
    else {
      iVar2 = (int)DAT_008807e0;
      if (DAT_008801ac != 5) {
        iVar2 = (int)DAT_008808e8;
      }
    }
    uVar1 = FUN_006e6b90();
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + iVar2 * 4),(float)extraout_ST0,
                 (_DAT_007f92ec + _DAT_007f92e4) * 0.5,0x3f800000,0x3f4ccccd,0x3f4ccccd,0x3f4ccccd,0
                 ,0xff,0xff,0xff,0x3fd9999a,1,0,0,uVar1);
    return;
  }
  return;
}

