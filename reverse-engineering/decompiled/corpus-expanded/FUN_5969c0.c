/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x5969c0; label: FUN_005969c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005969c0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_00637860(param_1,_DAT_00925018);
  iVar2 = 0;
  iVar1 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((*(uint *)(iVar1 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) {
        *(uint *)(iVar1 + 0xef0) = *(uint *)(iVar1 + 0xef0) | 0x80;
        FUN_00595af0(iVar1,param_1);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10d8;
    } while (iVar2 < DAT_0093d500);
  }
  return;
}

