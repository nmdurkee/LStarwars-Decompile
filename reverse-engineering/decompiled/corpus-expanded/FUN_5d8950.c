/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d8950; label: FUN_005d8950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d8950(void)

{
  FUN_005c1240(&DAT_0096e4f0,&DAT_0080b708,&DAT_0096d8b0);
  FUN_005c1240(&DAT_0096d940,&DAT_0080b708,&DAT_0096d980);
  _DAT_00971880 = DAT_00973708;
  _DAT_00971884 = DAT_0097370c;
  _DAT_00971888 = DAT_00973710;
  _DAT_0097188c =
       -(DAT_00973708 * DAT_00973718 + DAT_0097370c * DAT_0097371c + DAT_00973710 * DAT_00973720);
  _DAT_0096e540 = ABS(DAT_00973708);
  _DAT_0096e54c = 0;
  _DAT_0096e544 = ABS(DAT_0097370c);
  _DAT_0096e548 = ABS(DAT_00973710);
  _DAT_00971ac0 = _DAT_0096e4f0 & 0x7fffffff;
  _DAT_00971ac4 = _DAT_0096e4f4 & 0x7fffffff;
  _DAT_00971acc = _DAT_0096e4fc & 0x7fffffff;
  _DAT_00971ac8 = _DAT_0096e4f8 & 0x7fffffff;
  FUN_005c1600();
  FUN_005c1600();
  _DAT_00971af0 = 0;
  _DAT_00971af4 = 0;
  _DAT_00971af8 = 0;
  _DAT_00971afc = 0;
  _DAT_00971660 = _DAT_0096d940 & 0x7fffffff;
  _DAT_00971664 = _DAT_0096d944 & 0x7fffffff;
  _DAT_00971668 = _DAT_0096d948 & 0x7fffffff;
  _DAT_0097166c = _DAT_0096d94c & 0x7fffffff;
  FUN_005c1600();
  FUN_005c1600();
  _DAT_00971690 = 0;
  _DAT_00971694 = 0;
  _DAT_00971698 = 0;
  _DAT_0097169c = 0;
  return;
}

