/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b4a30; label: FUN_006b4a30
 */

void FUN_006b4a30(void *param_1)

{
  if (param_1 != (void *)0x0) {
    _memset(param_1,0,0x460);
    _free(param_1);
  }
  return;
}

