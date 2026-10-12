/* Ghidra pseudocode, not original source.
 * ev_48d4eb782bac12eedeead3c338e4f978b0df7732be8621fd20cf56d53bd7b1ed
 * Entry: 0x4018a0; label: FUN_004018a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004018a0(void *param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1 != (void *)0x0) {
    _memset(param_1,0,0x4304);
    puVar1 = (undefined1 *)((int)param_1 + 0x42c0);
    iVar3 = 0x40;
    do {
      puVar1[-0x40] = 0xff;
      *puVar1 = 0xff;
      puVar1 = puVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    puVar2 = (undefined4 *)((int)param_1 + 0x204);
    iVar3 = 0x20;
    do {
      *puVar2 = 0xffffffff;
      puVar2[1] = 0xffffffff;
      puVar2 = puVar2 + 0x85;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

