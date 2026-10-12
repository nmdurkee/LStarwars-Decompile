/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57c970; label: FUN_0057c970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0057c970(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (iVar2 = 0, 0 < param_1[1])) {
    do {
      iVar1 = FUN_004f8b10(*(int *)(*param_1 + iVar2 * 4) + 8,param_2);
      if (iVar1 == 0) {
        return *(undefined4 *)(*param_1 + iVar2 * 4);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[1]);
  }
  return 0;
}

