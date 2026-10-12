/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ad1d0; label: FUN_005ad1d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ad1d0(int param_1,int *param_2)

{
  short *psVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    iVar2 = 0;
    if ((short)param_2[2] != 0) {
      psVar1 = (short *)(*param_2 + 0x10e);
      do {
        if (((*(byte *)(psVar1 + 0x16) & 4) != 0) &&
           (((*psVar1 < 0 || (*(char *)((int)*psVar1 + *(int *)(param_1 + 0x2a94)) != '\0')) &&
            ((*(uint *)(psVar1 + -3) & 0x1000) != 0)))) {
          FUN_005a16b0(*(undefined4 *)(psVar1 + -0x7b),2,*(undefined4 *)(psVar1 + -0xd),0);
        }
        iVar2 = iVar2 + 1;
        psVar1 = psVar1 + 0x9e;
      } while (iVar2 < (int)(uint)*(ushort *)(param_2 + 2));
    }
  }
  return;
}

