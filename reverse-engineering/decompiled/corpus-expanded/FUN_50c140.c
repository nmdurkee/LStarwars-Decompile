/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50c140; label: FUN_0050c140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050c140(uint param_1,undefined1 *param_2)

{
  if (param_1 < 0xc) {
    FUN_004f1f10(param_2,(&PTR_DAT_008015f8)[param_1]);
    return;
  }
  if (param_1 - 0x80 < 4) {
    FUN_004f1f10(param_2,*(undefined4 *)(&DAT_00801428 + param_1 * 4));
    return;
  }
  *param_2 = 0;
  return;
}

