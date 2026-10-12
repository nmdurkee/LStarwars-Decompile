/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e0ff0; label: FUN_005e0ff0
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

