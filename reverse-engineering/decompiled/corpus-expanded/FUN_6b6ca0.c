/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b6ca0; label: FUN_006b6ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_006b6ca0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  
  puVar2 = _calloc(1,0x20);
  uVar1 = param_2[2];
  puVar2[1] = *param_2;
  *puVar2 = uVar1;
  puVar2[5] = param_2;
  pvVar3 = _calloc(2,4);
  puVar2[2] = pvVar3;
  return puVar2;
}

