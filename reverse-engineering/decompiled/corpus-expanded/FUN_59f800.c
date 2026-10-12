/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x59f800; label: FUN_0059f800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0059f800(undefined4 *param_1,byte *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  
  if (*param_2 != 0) {
    piVar5 = *(int **)(param_2 + 0x10);
    puVar3 = *(undefined1 **)(param_2 + 0x18);
    iVar4 = 0;
    if (*param_2 != 0) {
      do {
        iVar2 = (*(code *)(&PTR_FUN_0080551c)[(uint)*(byte *)(*piVar5 + 3) * 3])
                          (param_1,*piVar5,*puVar3);
        if (iVar2 == 0) {
          return 0;
        }
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar4 < (int)(uint)*param_2);
    }
  }
  FUN_0059de40(param_1,param_2);
  uVar1 = *(ushort *)(param_2 + 10);
  if ((((uVar1 & 0x1000) == 0) && (((uVar1 & 0x4000) != 0 || (DAT_0093b2a4 != 0)))) &&
     (((uVar1 & 0x2000) != 0 || (DAT_0093b2a4 == 0)))) {
    piVar5 = *(int **)(param_2 + 0xc);
    iVar4 = 0;
    if (0 < *piVar5) {
      do {
        FUN_0055a250(*param_1,**(undefined4 **)(piVar5[2] + iVar4 * 4),1,1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *piVar5);
    }
  }
  return 1;
}

