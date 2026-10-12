/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x746020; label: FUN_00746020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746020(int param_1)

{
  undefined4 *in_ECX;
  int *piVar1;
  
  FUN_00745f30();
  *in_ECX = &PTR_FUN_007e93a4;
  FUN_00748430(0x10000,1);
  FUN_00748430(0x10000,1);
  piVar1 = *(int **)(param_1 + 4);
  *(int **)(param_1 + 4) = piVar1 + 0x2f4;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_00748b90(param_1,0);
    *piVar1 = (int)&PTR_FUN_007e9320;
  }
  in_ECX[0x1e463] = piVar1;
  (**(code **)(*piVar1 + 8))("\\genShaders");
  (**(code **)(*(int *)in_ECX[0x1e463] + 4))
            ("./shaders;../nu2api/shaderBuilder;C:\\projects\\nu2api\\shaderBuilder");
  FUN_00749390(s___if_defined__SHADERBUILDER_DEBU_0082d6ef + 1,0x26b6f);
  (**(code **)(*(int *)in_ECX[0x1e463] + 0xc))(DAT_02974d1c,8,2);
  FUN_00746760("skinMatrix",8);
  FUN_00746760("blendShapes",8);
  (**(code **)(*(int *)in_ECX[0x1e463] + 0x10))(DAT_02974d20 != 0);
  return;
}

