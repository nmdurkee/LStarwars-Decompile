/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e1460; label: FUN_004e1460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004e1460(int param_1)

{
  if (*(short *)(param_1 + 0xfa) != DAT_00889086) {
    return 0;
  }
  if ((((DAT_00889038 != 0) && (DAT_0088904c != 0)) &&
      ((*(ushort *)(DAT_00889038 + 0x13a) & 0x30) == 0)) &&
     (((*(ushort *)(DAT_00889038 + 0x13a) & 2) != 0 && (DAT_00889048 == 0)))) {
    DAT_00889048 = DAT_00889038;
  }
  if (((DAT_0088903c != 0) && (DAT_00889050 != 0)) &&
     (((*(ushort *)(DAT_0088903c + 0x13a) & 0x30) == 0 &&
      (((*(ushort *)(DAT_0088903c + 0x13a) & 2) != 0 && (DAT_00889048 == 0)))))) {
    DAT_00889048 = DAT_0088903c;
  }
  if ((((DAT_00889040 != 0) && (DAT_00889054 != 0)) &&
      ((*(ushort *)(DAT_00889040 + 0x13a) & 0x30) == 0)) &&
     (((*(ushort *)(DAT_00889040 + 0x13a) & 2) != 0 && (DAT_00889048 == 0)))) {
    DAT_00889048 = DAT_00889040;
  }
  if (((DAT_00889044 != 0) && (DAT_00889058 != 0)) &&
     (((*(ushort *)(DAT_00889044 + 0x13a) & 0x30) == 0 &&
      (((*(ushort *)(DAT_00889044 + 0x13a) & 2) != 0 && (DAT_00889048 == 0)))))) {
    DAT_00889048 = DAT_00889044;
  }
  return 1;
}

