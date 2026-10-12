/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x595110; label: FUN_00595110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00595110(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  _DAT_009716f4 = *param_1;
  _DAT_009716f8 = param_1[1];
  _DAT_009716fc = param_1[2];
  _DAT_00971700 = *unaff_ESI;
  _DAT_00971704 = unaff_ESI[1];
  _DAT_00971708 = unaff_ESI[2];
  _DAT_0097170c = *in_ECX;
  _DAT_00971710 = in_ECX[1];
  _DAT_00971714 = in_ECX[2];
  _DAT_00971718 = *unaff_EDI;
  _DAT_0097171c = unaff_EDI[1];
  _DAT_00971720 = unaff_EDI[2];
  _DAT_00971724 = *param_2;
  _DAT_00971728 = param_2[1];
  _DAT_0097172c = param_2[2];
  _DAT_00971730 = *in_EAX;
  _DAT_00971734 = in_EAX[1];
  _DAT_00971738 = in_EAX[2];
  FUN_005fcad0(param_1);
  return;
}

