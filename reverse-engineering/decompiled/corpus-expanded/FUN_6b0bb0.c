/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6b0bb0; label: FUN_006b0bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

