/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69eb10; label: FUN_0069eb10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069eb10(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x58) != 1) {
    return 0xffffff7d;
  }
  uVar1 = FUN_0069e940();
  return uVar1;
}

