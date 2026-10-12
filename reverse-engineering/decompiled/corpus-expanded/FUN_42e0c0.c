/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42e0c0; label: FUN_0042e0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042e0c0(int param_1)

{
  if ((((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x40) != 0)) &&
      (param_1 == DAT_0087a7e0)) && ((DAT_0086e4e4 & 0x80) == 0)) {
    FUN_00561a00(*(undefined4 *)(DAT_00926c20 + DAT_00880fd0 * 4),0,0,0x3f19999a,0x3fa00000,1,0xff,0
                 ,0);
    FUN_0042b730();
    FUN_0042b080();
    FUN_00571b60(*(undefined4 *)(PTR_DAT_00802c54 + 0x138),0xf,DAT_0087a7e0 + 0x34);
  }
  return;
}

