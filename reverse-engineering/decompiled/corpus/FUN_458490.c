/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x458490; label: FUN_00458490
 */

float10 FUN_00458490(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)0;
  if (((float10)param_1 != fVar1) && ((float10)param_2 != fVar1)) {
    return (float10)(float)((float10)param_1 / (float10)param_2);
  }
  return fVar1;
}

