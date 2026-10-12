/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x678640; label: FUN_00678640
 */

void FUN_00678640(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  
  puVar1 = DAT_02947c74;
  if (DAT_02947c74 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
    if (DAT_0292fc68 != 0) {
      piVar2 = (int *)(DAT_0292fc68 + 0x198);
      do {
        if (*piVar2 == 0) {
          puVar1 = (undefined4 *)(DAT_0292fc68 + ((int)puVar1 * 3 + 0x33) * 8);
          goto LAB_00678683;
        }
        puVar1 = (undefined4 *)((int)puVar1 + 1);
        piVar2 = piVar2 + 6;
      } while ((int)puVar1 < 0x40);
      puVar1 = (undefined4 *)0x0;
    }
LAB_00678683:
    DAT_02947c74 = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      *(ushort *)((int)puVar1 + 6) = *(ushort *)((int)puVar1 + 6) | 1;
      *puVar1 = param_1;
      *(short *)(puVar1 + 1) = (short)param_4;
      *(undefined2 *)(puVar1 + 2) = 4;
      *(undefined4 *)(param_2 + 4) = 0;
      *(undefined4 *)(param_3 + 4) = 0;
    }
  }
  else {
    *(ushort *)((int)DAT_02947c74 + 6) = *(ushort *)((int)DAT_02947c74 + 6) | 1;
    *(short *)(puVar1 + 1) = (short)param_4;
    *(undefined2 *)(puVar1 + 2) = 4;
  }
  DAT_02961fdc = *(undefined2 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x48 + param_4 * 0x6c);
  return;
}

