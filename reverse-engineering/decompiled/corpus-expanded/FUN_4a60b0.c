/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a60b0; label: FUN_004a60b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004a60b0(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if ((((((*(uint *)(param_1 + 0x1fc) & 1) != 0) && ((*(uint *)(param_1 + 0x1fc) & 0x1000) != 0)) &&
       (*(char *)(param_1 + 0x28b) == '\0')) &&
      (((uVar2 = *(uint *)(*(int *)(param_1 + 0x54) + 4), (uVar2 & 0x10) != 0 &&
        (iVar3 = *(int *)(*(int *)(param_1 + 0x50) + 0xc), *(int *)(iVar3 + 0x104) != 0)) &&
       (cVar1 = *(char *)(param_1 + 0x7b5),
       (*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 0x8000) == 0)))) &&
     ((((uVar2 & 0x20) == 0 ||
       (((*(int *)(iVar3 + 0x108) != 0 && (*(int *)(iVar3 + 0x10c) != 0)) &&
        (*(int *)(iVar3 + 0x110) != 0)))) &&
      (((((cVar1 != '\x15' && (cVar1 != '\x17')) && (cVar1 != 'A')) &&
        ((cVar1 != '3' && (cVar1 != ';')))) && (cVar1 != '9')))))) {
    return 1;
  }
  return 0;
}

