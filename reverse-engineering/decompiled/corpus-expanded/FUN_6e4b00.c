/* Ghidra pseudocode, not original source.
 * ev_dd1ae0888c61f8b3b50bdf9044cbfd28d34bfcecc15a6b18504d89e7aa211813
 * Entry: 0x6e4b00; label: FUN_006e4b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e4b00(void)

{
  int *piStack_148;
  undefined1 *puStack_144;
  undefined4 uStack_140;
  undefined4 uStack_134;
  undefined1 local_130 [288];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puStack_144 = local_130;
  piStack_148 = DAT_029765cc;
  (**(code **)(*DAT_029765cc + 0x1c))();
  (**(code **)(*DAT_029765c8 + 0x20))(DAT_029765c8,uStack_134,&piStack_148);
  (**(code **)(*DAT_029765c8 + 0x28))
            (DAT_029765c8,uStack_140,puStack_144,piStack_148,uStack_8,uStack_c,uStack_10);
  return;
}

