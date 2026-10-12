/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a9320; label: FUN_004a9320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9320(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((*(char *)(param_1 + 0x28b) == '\0') &&
      ((((cVar1 = *(char *)(param_1 + 0x7b5), cVar1 == -1 ||
         ((cVar1 == '\x15' && (*(short *)(param_1 + 0x7aa) == 0x3e)))) ||
        ((cVar1 == '\x14' && (*(short *)(param_1 + 0x7aa) == 0x4d)))) ||
       (((cVar1 == '.' && (*(short *)(param_1 + 0x7aa) == 0x6f)) ||
        ((cVar1 == '\n' && (*(short *)(param_1 + 0x7aa) == 0x3c)))))))) &&
     ((*(char *)(param_1 + 0xe32) == '\x01' && (*(char *)(param_1 + 0x28c) != '\0')))) {
    uVar2 = FUN_0062c350(0x42c80000,_DAT_00925018);
    iVar3 = (-(uint)(*(short *)(param_1 + 0x1064) != DAT_007f1908) & 0xfffffffd) + 10;
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar3 * 4) != 0) {
      FUN_0062c680(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x1b,iVar3 * 0x40 + 0x834 + param_1,
                   uVar2,0,*(undefined2 *)(param_1 + 0x58));
    }
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x34) != 0) {
      FUN_0062c680(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x1b,param_1 + 0xa34,uVar2,0,
                   *(undefined2 *)(param_1 + 0x58));
    }
    FUN_00681f40("JgThrust",param_1 + 0x80);
  }
  return;
}

