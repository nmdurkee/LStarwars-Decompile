/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69ee00; label: FUN_0069ee00
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

