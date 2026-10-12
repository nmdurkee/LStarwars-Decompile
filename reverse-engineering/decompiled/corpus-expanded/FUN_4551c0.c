/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x4551c0; label: FUN_004551c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004551c0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  
  if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
    iVar1 = **(int **)(param_3 + 0xd0);
    *(undefined1 *)(iVar1 + 0x7b5) = 0x2e;
    if (*(char *)(iVar1 + 0xe32) == '\x01') {
      *(undefined2 *)(iVar1 + 0x7aa) = 0x6f;
    }
    else if ((*(byte *)(iVar1 + 0xe22) & 1) == 0) {
      *(undefined2 *)(iVar1 + 0x7aa) = 0x65;
    }
    else {
      *(undefined2 *)(iVar1 + 0x7aa) = 0x6e;
    }
    if (*(int *)(*(int *)(*(int *)(iVar1 + 0x50) + 0xc) + *(short *)(iVar1 + 0x7aa) * 4) == 0) {
      *(undefined2 *)(iVar1 + 0x7aa) = 0x65;
    }
    *(uint *)(iVar1 + 0x7bc) = *(uint *)(iVar1 + 0x7bc) & 0xffffffbf;
    if (*(int *)(*(int *)(*(int *)(iVar1 + 0x50) + 0xc) + *(short *)(iVar1 + 0x7aa) * 4) != 0) {
      fVar2 = (float10)FUN_0062e040((int)*(short *)(iVar1 + 0x1064),(int)*(short *)(iVar1 + 0x7aa),0
                                    ,0,1);
      *(float *)(iVar1 + 0x77c) = (float)fVar2;
      return 1;
    }
    *(undefined4 *)(iVar1 + 0x77c) = 0x3f800000;
  }
  return 1;
}

