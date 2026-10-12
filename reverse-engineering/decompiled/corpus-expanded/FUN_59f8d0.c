/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x59f8d0; label: FUN_0059f8d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0059f8d0(undefined4 param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  
  if (*param_2 != 0) {
    piVar3 = *(int **)(param_2 + 0x10);
    puVar4 = *(undefined1 **)(param_2 + 0x18);
    iVar2 = 0;
    if (*param_2 != 0) {
      do {
        iVar1 = (*(code *)(&PTR_FUN_0080551c)[(uint)*(byte *)(*piVar3 + 3) * 3])
                          (param_1,*piVar3,*puVar4);
        if (iVar1 == 0) {
          return 0;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar2 < (int)(uint)*param_2);
    }
  }
  FUN_0059e030(param_1,param_2);
  return 1;
}

