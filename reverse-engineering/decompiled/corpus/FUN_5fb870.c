/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fb870; label: FUN_005fb870
 */

void FUN_005fb870(undefined4 *param_1,uint param_2,undefined1 param_3)

{
  int *piVar1;
  int *in_ECX;
  undefined2 uStack_20;
  undefined2 uStack_1c;
  
  if (((undefined4 *)*in_ECX != param_1) || (*(ushort *)(in_ECX + 3) != param_2)) {
    FUN_005fb810();
    piVar1 = in_ECX + 2;
    *in_ECX = (int)param_1;
    *(undefined1 *)(in_ECX + 1) = param_3;
    *piVar1 = 0;
    *(short *)(in_ECX + 3) = (short)param_2;
    in_ECX[4] = 0;
    *(undefined2 *)(in_ECX + 5) = 0;
    *(undefined2 *)((int)in_ECX + 0x16) = 0;
    if (param_1 != (undefined4 *)0x0) {
      if (param_1[10] != 0) {
        *piVar1 = param_1[10];
        *(undefined2 *)(in_ECX + 5) = *(undefined2 *)(param_1 + 1);
        *(undefined2 *)((int)in_ECX + 0x16) = *(undefined2 *)((int)param_1 + 6);
        return;
      }
      (**(code **)(*(int *)*param_1 + 0x48))((int *)*param_1,param_2 & 0xffff,piVar1);
      (**(code **)(**(int **)*in_ECX + 0x44))(*(int **)*in_ECX,(short)in_ECX[3],&stack0xffffffd4);
      *(undefined2 *)(in_ECX + 5) = uStack_20;
      *(undefined2 *)((int)in_ECX + 0x16) = uStack_1c;
    }
  }
  return;
}

