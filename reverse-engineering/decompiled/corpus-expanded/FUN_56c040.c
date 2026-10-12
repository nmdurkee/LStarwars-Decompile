/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56c040; label: FUN_0056c040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056c040(int param_1)

{
  undefined2 uVar1;
  
  *(undefined1 *)(param_1 + 0x107a) = 0;
  uVar1 = FUN_00550070(*(undefined2 *)(param_1 + 0x278),-0x4000 - *(short *)(param_1 + 0x7a4),
                       0x40c00000);
  *(undefined2 *)(param_1 + 0x278) = uVar1;
  uVar1 = FUN_00550070(*(undefined2 *)(param_1 + 0x27c),0,0x41200000);
  *(undefined2 *)(param_1 + 0x27c) = uVar1;
  return;
}

