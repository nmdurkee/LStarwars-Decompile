/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x41a500; label: FUN_0041a500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0041a500(int param_1,int param_2,int param_3)

{
  uint *in_EAX;
  int in_ECX;
  uint uVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((in_ECX != -1) && (unaff_ESI != -1)) {
    if (((&DAT_007f23b8)[in_ECX * 3] & *in_EAX) != 0) {
      uVar1 = ~(&DAT_007f23b8)[in_ECX * 3] & *in_EAX;
      *in_EAX = uVar1;
      *in_EAX = (&DAT_007f23b8)[unaff_ESI * 3] | uVar1;
      return;
    }
  }
  if ((param_1 != -1) && (unaff_EDI != -1)) {
    if ((*in_EAX & (&DAT_007f23b8)[param_1 * 3]) != 0) {
      uVar1 = ~(&DAT_007f23b8)[param_1 * 3] & *in_EAX;
      *in_EAX = uVar1;
      *in_EAX = (&DAT_007f23b8)[unaff_EDI * 3] | uVar1;
      return;
    }
  }
  if ((param_2 != -1) && (param_3 != -1)) {
    if ((*in_EAX & (&DAT_007f23b8)[param_2 * 3]) != 0) {
      uVar1 = ~(&DAT_007f23b8)[param_2 * 3] & *in_EAX;
      *in_EAX = uVar1;
      *in_EAX = (&DAT_007f23b8)[param_3 * 3] | uVar1;
    }
  }
  return;
}

