/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42df30; label: FUN_0042df30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042df30(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((*(char *)(param_2 + 0x91) == '\x02') && (*(float *)(param_2 + 0x44) < 0.25)) {
    uVar1 = FUN_00650dc0("SwPPad");
    *(undefined2 *)(param_2 + 0x8c) = uVar1;
  }
  return;
}

