/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0ff0; label: FUN_005e0ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

ushort FUN_005e0ff0(undefined4 param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  undefined2 in_FPUControlWord;
  undefined1 local_4;
  
  fVar1 = param_3;
  if (param_3 < 0.0) {
    param_3 = 0.0;
  }
  if (param_3 <= 255.0) {
    if (fVar1 < 0.0) {
      fVar1 = 0.0;
    }
  }
  else {
    fVar1 = 255.0;
  }
  local_4 = (undefined1)(int)ROUND(fVar1);
  return CONCAT11((char)((ushort)in_FPUControlWord >> 8),local_4) | 0xc00;
}

