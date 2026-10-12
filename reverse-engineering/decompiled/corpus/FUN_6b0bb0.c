/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b0bb0; label: FUN_006b0bb0
 */

void FUN_006b0bb0(void *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_006afc50((int)param_1 + 0x10);
  puVar1 = (undefined4 *)((int)param_1 + 0x30);
  iVar2 = 7;
  do {
    _free((void *)*puVar1);
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _free(*(void **)((int)param_1 + 0x24));
  _free(*(void **)((int)param_1 + 0x98));
  _free(*(void **)((int)param_1 + 0xa0));
  _memset(param_1,0,0xb4);
  return;
}

