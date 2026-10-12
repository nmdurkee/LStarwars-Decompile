/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504030; label: FUN_00504030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00504030(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *in_EDX;
  undefined4 unaff_ESI;
  undefined4 *unaff_EDI;
  
  puVar2 = (undefined4 *)(*in_EDX + 0xfU & 0xfffffff0);
  *in_EDX = (int)puVar2;
  puVar1 = (undefined4 *)0x0;
  switch(unaff_ESI) {
  case 0:
  case 4:
  case 6:
  case 0xb:
  case 0xc:
  case 0xd:
    *in_EDX = (int)(puVar2 + 3);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar1 = puVar2;
    break;
  case 1:
  case 2:
  case 3:
  case 5:
  case 7:
  case 9:
  case 0xe:
    *in_EDX = (int)(puVar2 + 4);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar1 = puVar2;
    break;
  case 8:
    *in_EDX = (int)(puVar2 + 6);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar1 = puVar2;
    break;
  case 10:
    *in_EDX = (int)(puVar2 + 5);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar1 = puVar2;
  }
  puVar1[1] = unaff_ESI;
  if (unaff_EDI == (undefined4 *)0x0) {
    *param_1 = puVar1;
    return;
  }
  *unaff_EDI = puVar1;
  return;
}

