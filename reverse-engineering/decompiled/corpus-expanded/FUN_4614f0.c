/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x4614f0; label: FUN_004614f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004614f0(int param_1,int param_2,float param_3)

{
  int iVar1;
  
  if (param_3 != 0.0) {
    if (*(float *)(param_1 + 0x18) < 0.5) {
      iVar1 = FUN_006e6b90();
      param_3 = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
      if (*(int *)(param_1 + 0x14) == 1) {
        param_3 = 1.0 - param_3;
      }
      FUN_00485b70(param_2,0,param_3);
      DAT_0087a1e4 = 1;
      return;
    }
    FUN_00485b70(param_2,1,0x3f800000);
    FUN_004b79a0(*(undefined1 *)(param_2 + 0xa4),(int)DAT_00880868,0x3f800000,0xffffffff,0xffffffff,
                 0xffffffff,(int)DAT_00880e8c,*(undefined1 *)(param_2 + 0xa5),(int)DAT_00880868,
                 0x3f800000,0xffffffff,0xffffffff,0xffffffff,(int)DAT_00880e8c);
  }
  return;
}

