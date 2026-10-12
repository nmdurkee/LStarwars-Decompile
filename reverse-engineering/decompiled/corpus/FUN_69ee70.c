/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69ee70; label: FUN_0069ee70
 */

undefined4 FUN_0069ee70(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      _free((void *)*param_1);
    }
    if ((void *)param_1[4] != (void *)0x0) {
      _free((void *)param_1[4]);
    }
    if ((void *)param_1[5] != (void *)0x0) {
      _free((void *)param_1[5]);
    }
    _memset(param_1,0,0x168);
  }
  return 0;
}

