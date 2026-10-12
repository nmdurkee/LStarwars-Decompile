/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x6326b0; label: FUN_006326b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006326b0(float param_1)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((param_1 < 0.9999) || (in_EAX[3] != 0)) {
    (**(code **)(*(int *)*in_EAX + 0xe4))((int *)*in_EAX,0x1b,1);
    (**(code **)(*(int *)*in_EAX + 0xe4))((int *)*in_EAX,0x13,5);
    (**(code **)(*(int *)*in_EAX + 0xe4))((int *)*in_EAX,0x14,6);
    (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,4,4);
    (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,2,2);
    uVar2 = 0;
    uVar1 = 3;
  }
  else {
    (**(code **)(*(int *)*in_EAX + 0xe4))((int *)*in_EAX,0x1b,0);
    (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,4,2);
    uVar2 = 2;
    uVar1 = 2;
  }
  (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,uVar1,uVar2);
  (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,5,2);
  (**(code **)(*(int *)*in_EAX + 0x10c))((int *)*in_EAX,0,1,4);
  return;
}

