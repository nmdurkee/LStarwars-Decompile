/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66e8f0; label: FUN_0066e8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066e8f0(void)

{
  uint *puVar1;
  
  if ((DAT_0292186c != 0) && (puVar1 = *(uint **)(DAT_0292186c + 0x90), puVar1 != (uint *)0x0)) {
    if ((DAT_02924b34 <= puVar1) && (puVar1 < DAT_02924b34 + 0xc800)) {
      puVar1 = (uint *)*puVar1;
    }
    FUN_0066d3a0(puVar1,*(undefined2 *)(DAT_0292186c + 0x6c));
  }
  return;
}

