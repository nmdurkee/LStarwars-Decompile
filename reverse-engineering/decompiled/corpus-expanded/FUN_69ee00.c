/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69ee00; label: FUN_0069ee00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069ee00(undefined4 *param_1,undefined4 param_2)

{
  void *pvVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    _memset(param_1,0,0x168);
    param_1[1] = 0x4000;
    pvVar1 = _malloc(0x4000);
    *param_1 = pvVar1;
    param_1[6] = 0x400;
    pvVar1 = _malloc(0x1000);
    param_1[4] = pvVar1;
    pvVar1 = _malloc(param_1[6] * 8);
    param_1[5] = pvVar1;
    param_1[0x54] = param_2;
    return 0;
  }
  return 0xffffffff;
}

