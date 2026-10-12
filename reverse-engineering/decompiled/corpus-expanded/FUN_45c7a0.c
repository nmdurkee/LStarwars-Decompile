/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45c7a0; label: FUN_0045c7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045c7a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    switch(*(undefined4 *)(param_1 + 0x14)) {
    case 0:
      if (*(float *)(param_1 + 0x18) < 0.5) {
        iVar1 = FUN_006e6b90();
        FUN_00485b70(param_2,0,(&DAT_029899a0)[iVar1 >> 1 & 0x7fff]);
        return;
      }
      FUN_00485b70(param_2,1,0x3f800000);
      FUN_004b79a0(*(undefined1 *)(param_2 + 0xa4),(int)DAT_00880868,0x3f800000,0xffffffff,
                   0xffffffff,0xffffffff,0xffffffff,*(undefined1 *)(param_2 + 0xa5),
                   (int)DAT_00880868,0x3f800000,0xffffffff,0xffffffff,0xffffffff,0xffffffff);
      return;
    case 1:
    case 2:
      iVar1 = FUN_006e6b90();
      FUN_00485b70(param_2,0,1.0 - (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff]);
    }
  }
  return;
}

