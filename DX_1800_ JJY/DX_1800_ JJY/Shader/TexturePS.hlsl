
Texture2D resource : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
    float4 color = resource.Sample(samp, input.uv);

    if (color.x > 0.9f && color.y > 0.9f && color.z > 0.9f)
    {
        color.w = 0;
    }

    return color;
}